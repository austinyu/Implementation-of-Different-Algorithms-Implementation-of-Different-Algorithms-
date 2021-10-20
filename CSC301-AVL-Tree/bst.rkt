#lang racket

;;; bst.rkt
;;;   A simple implementation of non-balanced binary-search trees.
;;;
;;; Samuel A. Rebelsky
;;; CSC-301-01 2021Fa

; +---------+--------------------------------------------------------
; | Exports |
; +---------+

(provide tree-new
         tree-height
         tree-size
         tree-insert!
         tree-insert-balance!
         tree-iterate-preorder!
         tree-keys
         tree-values
         tree-find
         tree-kth
         tree-root
         ) 

; +-------+----------------------------------------------------------
; | Notes |
; +-------+

#| EMPTY TREES
We follow Knuth's model in using special values for the empty
tree, whether it's the whole tree or the thing below a leaf.
We name that value NOD.  The advantage of using a special value
is that we can set attributes and then no longer need to check
whether or not that thing is a special value (at least in most
cases).
|#

#| NODES VS TREES
We are using node and tree almost interchangably within this file.  The 
procedures we provide to the outside world all begin with `tree-`.
|#

#| STRUCTS
Racket structs let us create simple structures along with the constructor,
accessors, and, as appropriate, mutators.

See https://docs.racket-lang.org/reference/structures.html
and https://docs.racket-lang.org/guide/define-struct.html

For example, our `node` type has operations like

* `(node? exp)`
* `(node-key node)`
* `(node-value node)`
* `(set-node-value! node new-value)`

It also has

* `(make-node key value left right height size)`
|#

#| TRANSPARENCY
We have made the node struct transparent mostly so that we
can more easily check and debug the node operations.
|#

; +---------+--------------------------------------------------------
; | Structs |
; +---------+

; Nodes in our tree
(struct node (key 
              [value #:mutable] 
              [height #:mutable]
              [size #:mutable]
              [left #:mutable]
              [right #:mutable])
             #:constructor-name make-node
             #:transparent)

; Our trees
(struct tree ([root #:mutable]))

; Boxed values
(struct box ([contents #:mutable]))

; +-----------+------------------------------------------------------
; | Constants |
; +-----------+

;;; NOD : nod?
;;; The empty node.
(define NOD (make-node "" "" 0 0 null null))

; +---------------------+--------------------------------------------
; | Exported Procedures |
; +---------------------+

;;; (tree-new) -> tree?
;;; Create a new tree
(define tree-new
  (lambda ()
    (tree NOD)))

;;; (tree-height tree) -> integer?
;;;   tree : tree?
;;; Get the height of the tree
(define tree-height
  (lambda (tree)
    (node-height (tree-root tree))))

;;; (tree-size tree) -> integer?
;;;   tree : tree?
;;; Get the height of the tree
(define tree-size
  (lambda (tree)
    (node-size (tree-root tree))))

;;; (tree-insert! tree key value) -> void?
;;;   tree : tree?
;;;   key : string?
;;;   value : string?
;;; Insert a key-value pair into the tree
(define tree-insert!
  (lambda (tree key value)
    (cond
      [(not (tree? tree))
       (error "tree-insert: Expects a tree as the first parameter.")]
      [(not (string? key))
       (error "tree-insert: Expects a string as the second parameter.")]
      [(not (string? value))
       (error "tree-insert: Expects a string as the third parameter.")]
      [else
       (set-tree-root! tree (node-insert! (tree-root tree) key value))])))

;;; (tree-insert-balance! tree key value) -> void?
;;;   tree : tree?
;;;   key : string?
;;;   value : string?
;;; Insert a key-value pair into the tree and balance them
(define tree-insert-balance!
  (lambda (tree key value)
    (cond
      [(not (tree? tree))
       (error "tree-insert-balance: Expects a tree as the first parameter.")]
      [(not (string? key))
       (error "tree-insert-balance: Expects a string as the second parameter.")]
      [(not (string? value))
       (error "tree-insert-balance: Expects a string as the third parameter.")]
      [else
       (set-tree-root! tree (node-insert-balance! (tree-root tree) key value))])))

;;; (tree-iterate-preorder! tree proc!) -> void?
;;;   tree : tree?
;;;   proc! : (string?,string?) -> void?
;;; Apply proc to every key/value pair in the tree
(define tree-iterate-preorder!
  (lambda (tree proc!)
    (node-iterate-preorder! (tree-root tree) proc!)))

;;; (tree-keys tree) -> listof string?
;;;   tree : tree?
;;; Get a list of all the keys in the tree.
(define tree-keys
  (lambda (tree)
    (let ([keys (box null)])
      (tree-iterate-preorder! tree
                              (lambda (key value)
                                (set-box-contents! keys (cons key (box-contents keys)))))
      (reverse (box-contents keys)))))

;;; (tree-values tree) -> listof string?
;;;   tree : tree?
;;; Get a list of all of the values in the tree.
(define tree-values
  (lambda (tree)
    (let ([values (box null)])
      (tree-iterate-preorder! tree
                              (lambda (key value)
                                (set-box-contents! values (cons value (box-contents values)))))
      (reverse (box-contents values)))))

;;; (tree-find tree key) -> string? or #f
;;;   tree : tree?
;;;   key : string?
;;; Find the value associated with key in tree.  If there is no such value,
;;; returns #f.
(define tree-find
  (lambda (tree key)
    (node-find (tree-root tree) key)))

;;; (tree-kth tree k) -> string? of #f
;;;   tree : tree?
;;;   k : non-negative integer?
;;; Get the kth element of the tree, assuming the tree is read in dfs, left-to-right, inorder
(define tree-kth
  (lambda (tree k)
   (node-kth (tree-root tree) k))) ; STUB

;;; (node-kth node k) -> string? of #f
;;;   tree : tree?
;;;   k : non-negative integer?
;;; Get the kth element of the tree, assuming the tree is read in dfs, left-to-right, inorder

(define node-kth
  (lambda (node k)
    (cond [(> k (node-size node)) #f]
          [(< k 1) #f]
          [(= k (+ (node-size (node-left node)) 1)) (node-key node)] 
          [(> k (node-size (node-left node))) (node-kth (node-right node) (- (- k (node-size (node-left node))) 1))] ; move right with k - left.size - 1
          [(<= k (node-size (node-left node))) (node-kth (node-left node) k)] ; move left with with k
          [else #f] ; I dont know what other cases there are, but i need an else 
          ))) 
; !!! Remember to return the value!!! NOt key !!!!!!
; +------------------+-----------------------------------------------
; | Local Procedures |
; +------------------+

;;; (node-empty? node) -> boolean
;;;   node : node?
;;; Determines if we have the empty node.
(define node-empty?
  (lambda (node)
    (eq? node NOD)))

(define single-right-rotation
 (lambda (node)
   (let* ([A node]
          [B (node-left A)]
          [alpha (node-left B)]
          [beta (node-right B)]
          [gamma (node-right A)])
     (set-node-left! A beta)
     (set-node-right! A gamma)
     (set-node-left! B alpha)
     (set-node-right! B A)
     (node-update-attributes! A)
     (node-update-attributes! B)
     B ))) ; C


(define single-left-rotation
 (lambda (node)
   (let* ([A node]
          [B (node-right A)]
          [alpha (node-left B)]
          [beta (node-right B)]
          [gamma (node-left A)])
     (set-node-left! A gamma)
     (set-node-right! A alpha)
     (set-node-left! B A)
     (set-node-right! B beta)
     (node-update-attributes! A)
     (node-update-attributes! B)
     B ))) ; C

(define double-right-rotation
  (lambda (node)
    (let* ([A node]
          [B (node-left A)]
          [delta (node-right A)]
          [C (node-right B)]
          [alpha (node-left B)]
          [beta (node-left C)]
          [gamma (node-right C)])
     (set-node-left! C B)
     (set-node-right! C A)
     (set-node-left! B alpha)
     (set-node-right! B beta)
     (set-node-left! A gamma)
     (set-node-right! A delta)
     (node-update-attributes! A)
     (node-update-attributes! B)
     (node-update-attributes! C)
     C))) ; C

(define double-left-rotation
  (lambda (node)
    (let* ([A node]
          [alpha (node-left A)]
          [B (node-right A)]
          [delta (node-right B)]
          [C (node-left B)]
          [beta (node-left C)]
          [gamma (node-right C)])
     (set-node-left! C A)
     (set-node-right! C B)
     (set-node-left! B gamma)
     (set-node-right! B delta)
     (set-node-left! A alpha)
     (set-node-right! A beta)
     (node-update-attributes! A)
     (node-update-attributes! B)
     (node-update-attributes! C)
     C ))) ; C

(define tree-balance!
  (lambda (tree)
    (node-balance! (tree-root tree))))

#|
(define node-balance!
  (lambda (node)
    (display "Balance    ")
    (cond [(node-empty? node) node]
          [(< 1 (- (node-height (node-left node)) (node-height (node-right node)))) ; left subtree  
           (cond [(> (node-height (node-left (node-left node))) (node-height (node-right (node-left node)))) ; case 1: line case
                  ; (display "left subtree: case1 line ")
                  (single-right-rotation node)
                  ]
                 [else ; case 2: triangle
                  ; (display "left subtree: case2 triangle ")
                  (double-right-rotation node)
                  ])]
          [(< 1 (- (node-height (node-right node)) (node-height (node-left node)))) ; right subtree
           (cond [(> (node-height (node-right (node-right node))) (node-height (node-left (node-right node)))) ; case 1: line case
                  ; (display "right subtree: case1 line ")
                  (single-left-rotation node)
                  ]
                 [else ; case 2: triangle case
                  ; (display "right subtree: case2 triangle ")
                  (double-left-rotation node)
                  ])]
          [else ; no balance needed
           node])))
|#

; return void
(define node-balance!
  (lambda (node)
    ;(display "Balance    ")
    (cond [(node-empty? node) node]
          [(< 1 (- (node-height (node-left node)) (node-height (node-right node)))) ; left subtree  
           (cond [(> (node-height (node-left (node-left node))) (node-height (node-right (node-left node)))) ; case 1: line case
                  ; (display "left subtree: case1 line ")
                  (node-update-attributes! (single-right-rotation node))
                  ]
                 [else ; case 2: triangle
                  ; (display "left subtree: case2 triangle ")
                   (node-update-attributes! (double-right-rotation node))
                  ])]
          [(< 1 (- (node-height (node-right node)) (node-height (node-left node)))) ; right subtree
           (cond [(> (node-height (node-right (node-right node))) (node-height (node-left (node-right node)))) ; case 1: line case
                  ; (display "right subtree: case1 line ")
                   (node-update-attributes! (single-left-rotation node))
                  ]
                 [else ; case 2: triangle case
                  ; (display "right subtree: case2 triangle ")
                   (node-update-attributes! (double-left-rotation node))
                  ])]
          [else ; no balance needed
           (node-update-attributes! node)])))

;;; (node-insert-balance! node key value) -> node?
;;;   node : node?
;;;   key : string?
;;;   value : string?
;;; Insert a key-value pair in the tree rooted at node and rebalance the tree
(define node-insert-balance!
  (lambda (node key value)
    (cond
      [(node-empty? node)
       (make-node key value 1 1 NOD NOD)]
      [(string=? key (node-key node))
       (set-node-value! node value)
       node]
      [(string<? key (node-key node))
       (set-node-left! node (node-insert-balance! (node-left node) key value))
       (node-balance! node)]
      [else
       (set-node-right! node (node-insert-balance! (node-right node) key value))
       (node-balance! node)])))


;;; (node-insert! node key value) -> node?
;;;   node : node?
;;;   key : string?
;;;   value : string?
;;; Insert a key-value pair in the tree rooted at node.
(define node-insert!
  (lambda (node key value)
    (cond
      [(node-empty? node)
       (make-node key value 1 1 NOD NOD)]
      [(string=? key (node-key node))
       (set-node-value! node value)
       node]
      [(string<? key (node-key node))
       (set-node-left! node (node-insert! (node-left node) key value))
       (node-update-attributes! node)]
      [else
       (set-node-right! node (node-insert! (node-right node) key value))
       (node-update-attributes! node)])))

;;; (node-update-attributes! node) -> node?
;;;   node : node?
;;; Updates the primary attributes of the node (e.g., size and height)
;;; after potential changes to the children.
(define node-update-attributes!
  (lambda (node)
    (set-node-height! node 
                      (+ 1 (max (node-height (node-left node))
                                (node-height (node-right node)))))
    (set-node-size! node 
                    (+ 1  
                       (node-size (node-left node))
                       (node-size (node-right node))))
    node))

;;; (node-iterate-preorder! node proc!) -> void?
;;;   node : ndoe?
;;;   proc! : (string?,string?) -> void?
;;; Apply proc to every key/value pair in the tree
(define node-iterate-preorder!
  (lambda (node proc!)
    (when (not (node-empty? node))
      (node-iterate-preorder! (node-left node) proc!)
      (proc! (node-key node) (node-value node))
      (node-iterate-preorder! (node-right node) proc!))))


;;; (node-find tree key) -> string? or #f
;;;   node : tree?
;;;   key : string?
;;; Find the value associated with key in the tree rooted at the given node.
;;; If there is no such value, returns #f.
(define node-find
  (lambda (node key)
    (cond
      [(node-empty? node)
       #f]
      [(string=? key (node-key node))
       (node-value node)]
      [(string<? key (node-key node))
       (node-find (node-left node) key)]
      [else
       (node-find (node-right node) key)])))

#|
(define leftTriangle (tree-new))
(for-each (lambda (kv)
            (tree-insert! leftTriangle (car kv) (cadr kv)))
          '(("G" "1")
            ("B" "1") ("H" "1")
            ("A" "1") ("E" "1") ("I" "1")
            ("D" "1") ("F" "1")
            ("C" "1") ))

(define rightTriangle (tree-new))
(for-each (lambda (kv)
            (tree-insert! rightTriangle (car kv) (cadr kv)))
          '(("C" "1")
            ("B" "1") ("H" "1")
            ("A" "1") ("E" "1") ("I" "1") 
            ("D" "1") ("F" "1")
            ("G" "1")))
|#

(define simple (tree-new))
(for-each (lambda (kv)
            (tree-insert! simple (car kv) (cadr kv)))
          '(("F" "1")
            ("D" "1") ("G" "1")
            ("B" "1") ("E" "1") ("H" "1") ("I" "1")
            ("A" "1") ("C" "1")
            ))

(define withBalance (tree-new))
(for-each (lambda (kv)
            (tree-insert-balance! withBalance (car kv) (cadr kv)))
          '(("E" "1")
            ("D" "1") ("C" "1")
            ("B" "1") ("A" "1")))


; (tree-iterate-preorder! t1 (lambda (key value) (fprintf (current-output-port) "~a:~a~n" key value)))
; (node-height (single-right-rotation (tree-root t1)))
