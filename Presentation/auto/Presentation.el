(TeX-add-style-hook "Presentation"
 (lambda ()
    (LaTeX-add-bibliographies
     "Ref")
    (LaTeX-add-labels
     "sec:discrete-logarithm"
     "eq:diffie–hellman-1"
     "eq:diffie–hellman-2"
     "sec:elgamal-cryptosystem"
     "fig:basic-elgamal-encryption")
    (TeX-run-style-hooks
     "algorithmic"
     "amssymb"
     "amsmath"
     ""
     "latex2e"
     "beamer10"
     "beamer"
     "hyperref=true")))

