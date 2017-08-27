#lang slideshow

(define c (circle 30)) 
(define r (rectangle 20 40)) 

(define (square n)
    (filled-rectangle n n)) 

(define x 1)

(list '(a) '(b)) 
(append '(a b c) '(1 2 3))
(car (list 'a 'b 'c))
(cdr '((a b) c))
(cdr '(a))
(cons 'a '((b)))
(cons '(a) '())

(define init-state '((blank 5 4) (6 1 8) (7 3 2)))
(car init-state)

; some recursive functions
(define (sum-n n)
(cond ((= n 0) 0)
(else (+ n (sum-n (- n 1))))
)
)
; to test it
(sum-n 6)

(define (factorial n)
(cond ((= n 0) 1)
(else (* n (factorial (- n 1))))
)
)
; to test it
(factorial 5)

