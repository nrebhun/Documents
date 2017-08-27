;; Computes x^2
(defun square (x)
  (* x x)) 

;; Computes area of circle with given radius
(defun circle-space (x)
   (* (square x)  3.14))

;; Converts temperature in Fahrenheit degrees "f" to Celcius degrees
(defun temp-change (f)
  (float  (* 5/9 (- f 32))))

;; Returns first item in list "l" if the list contains an even number of elements
;; otherwise, return last item in the list
(defun front-or-back (l)
  (if (= (mod (length l) 2) 0)
    (first l)
    (last l)))