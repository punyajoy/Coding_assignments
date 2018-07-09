#lang racket
(define  ( maximum l)
  (if (= (length l) 1)
      (car l)
      (if (> (car l) (maximum (cdr l)))
          (car l)
          (maximum (cdr l)))))

(define l'(1 2 3 4 5)) 
(maximum l)