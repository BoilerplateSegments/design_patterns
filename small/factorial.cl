;; Tested on SBCL 2.0
(defun factorial (n)
  (if (= n 1)              
      1                           
      (+ n (factorial (- n 1))))) 

(write-line "Please enter a number...")  
(let ((x (read)))
(format t "~D! is ~D" x (factorial x)))
