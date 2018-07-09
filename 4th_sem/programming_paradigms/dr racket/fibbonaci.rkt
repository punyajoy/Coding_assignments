#lang racket

(define  (fibbonaci n)(cond(
                       (= n 1)0)
                              (
                               (= n 2) 1)
                              (else
                               (+ (fibbonaci(- n 1))(fibbonaci(- n 2))
                               )
                              )
  )
)

(fibbonaci 5)