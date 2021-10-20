CFLAGS = -Wall -O
# CFLAGS = -Wall -O -DTRACE

SORTS = insertion-sort.o \
        recursive-merge-sort.o \
		tim-sort.o \
		radix-sort.o \
		bucket-sort.o \

default: isort competition competition_commandLine

tests: test-fake test-isort test-rms test-sbs test-radix test-bucket

# +-----------------+------------------------------------------------
# | Primary Targets |
# +-----------------+

competition: competition.o $(SORTS) strutils.o bucket.o
	$(CC) $(CFLAGS) -o $@ $^

competition_commandLine: competition_commandLine.o $(SORTS) strutils.o bucket.o
	$(CC) $(CFLAGS) -o $@ $^

# +-------+----------------------------------------------------------
# | Tests |
# +-------+

test-fake: test-fake.o fake-sort.o sort-tester.o strutils.o
	$(CC) $(CFLAGS) -o $@ $^

test-isort: test-insertion-sort.o insertion-sort.o sort-tester.o strutils.o
	$(CC) $(CFLAGS) -o $@ $^

test-rms: test-rms.o recursive-merge-sort.o sort-tester.o strutils.o
	$(CC) $(CFLAGS) -o $@ $^

test-sbs: test-sbs.o simple-bucket-sort.o recursive-merge-sort.o sort-tester.o strutils.o bucket.o
	$(CC) $(CFLAGS) -o $@ $^

test-tim: test-tim.o tim-sort.o sort-tester.o strutils.o insertion-sort.o
	$(CC) $(CFLAGS) -o $@ $^

test-radix: test-radix.o radix-sort.o sort-tester.o strutils.o 
	$(CC) $(CFLAGS) -o $@ $^

test-bucket: test-bucket.o bucket-sort.o sort-tester.o strutils.o bucket.o recursive-merge-sort.o
	$(CC) $(CFLAGS) -o $@ $^

# +-------+----------------------------------------------------------
# | Sorts |
# +-------+

isort: isort.o bucket-sort.o sort-tester.o strutils.o sort-main.o bucket.o recursive-merge-sort.o
	$(CC) $(CFLAGS) -o $@ $^

# +------+-----------------------------------------------------------
# | Misc |
# +------+

tarball:
	tar cvf sort.tar Makefile *.c *.h
