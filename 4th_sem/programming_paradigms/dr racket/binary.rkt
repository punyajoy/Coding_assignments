#lang racket


(define X (cons 7 8))
(define Y (cons 5 6))
(define W (cons 2 X))
(define U (cons 3 Y))
(define V (cons W U))
(define T (cons 1 V))

T


