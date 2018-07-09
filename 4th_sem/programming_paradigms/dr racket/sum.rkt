#lang racket
(define x 8)
(define (sum n)
  (if
   (= n 0)0(+ n (sum (- n 1)))
   )
)
(sum x)
        

 
