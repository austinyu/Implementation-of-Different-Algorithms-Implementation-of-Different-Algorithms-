#lang racket
(require "bst.rkt")
(require 2htdp/batch-io)


;;; (random-string-element str) -> char?
;;;   str : string? (nonempty)
;;; Randomly select an element of str
(define random-string-element
  (lambda (str)
    (string-ref str (random (string-length str)))))

;;; (random-vowel) -> char?
;;; Randomly select a lowercase vowel
(define random-vowel
  (lambda ()
    (random-string-element "uoiea")))

;;; (random-consonant) -> char?
;;; Randomly select an lowercase consonant
(define random-consonant
  (lambda ()
    (random-string-element "zyxwvtsrqpnmlkjhgfdcb")))

;;; (random-word) -> string?
;;; Generate a random word-like value
(define random-word
  (lambda ()
    (string (random-consonant) (random-vowel)
            (random-consonant) (random-vowel)
            (random-consonant) (random-vowel))))

;;; (random-tree n) -> tree?
;;;   n : integer? (not negative)
;;; Randomly generate a tree of the appropriate size
(define random-tree
  (lambda (n)
    (letrec ([kernel (lambda (tree)
                       (if (= (tree-size tree) n)
                           tree
                           (let ([word (random-word)])
                             (tree-insert! tree word word)
                             (kernel tree))))])
      (kernel (tree-new)))))

;;; (random-tree-balance n) -> tree?
;;;   n : integer? (not negative)
;;; Randomly generate a tree of the appropriate size
(define random-tree-balance
  (lambda (n)
    (letrec ([kernel (lambda (tree)
                       (if (= (tree-size tree) n)
                           tree
                           (let ([word (random-word)])
                             (tree-insert-balance! tree word word)
                             (kernel tree))))])
      (kernel (tree-new)))))



; 64, 128, 256, 512, 1024, 2048, and 4096
(define experiment-height-balance
  (lambda (n size) 
    (cond [(= n 1) n]
    [else (display (format "~v, " (tree-height (random-tree-balance size))) balance)
    (experiment-height-balance (- n 1) size)]
    )))

(define balance (open-output-file "output/balanced_descending.csv"))

(display "64, " balance)
(experiment-height-balance 1000 64)
(display "\n" balance)

(display "128, " balance)
(experiment-height-balance 1000 128)
(display "\n" balance)

(display "256, " balance)
(experiment-height-balance 1000 256)
(display "\n" balance)

(display "512, " balance)
(experiment-height-balance 1000 512)
(display "\n" balance)

(display "1024, " balance)
(experiment-height-balance 1000 1024)
(display "\n" balance)

(display "2048, " balance)
(experiment-height-balance 1000 2048)
(display "\n" balance)

(display "4096, " balance)
(experiment-height-balance 1000 4096)
(display "\n" balance)

(close-output-port balance)

; =======================================

; 64, 128, 256, 512, 1024, 2048, and 4096
(define experiment-height-random
  (lambda (n size) 
    (cond [(= n 1) n]
    [else (display (format "~v, " (tree-height (random-tree size))) rand)
    (experiment-height-random (- n 1) size)]
    )))

(define rand (open-output-file "output/random_descending.csv"))

(display "64, " rand)
(experiment-height-random 1000 64)
(display "\n" rand)

(display "128, " rand)
(experiment-height-random 1000 128)
(display "\n" rand)

(display "256, " rand)
(experiment-height-random 1000 256)
(display "\n" rand)

(display "512, " rand)
(experiment-height-random 1000 512)
(display "\n" rand)

(display "1024, " rand)
(experiment-height-random 1000 1024)
(display "\n" rand)

(display "2048, " rand)
(experiment-height-random 1000 2048)
(display "\n" rand)

(display "4096, " rand)
(experiment-height-random 1000 4096)
(display "\n" rand)

(close-output-port rand)


