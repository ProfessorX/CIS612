(TeX-add-style-hook "Presentation"
 (lambda ()
    (LaTeX-add-bibliographies
     "Ref")
    (LaTeX-add-labels
     "sec:discrete-logarithm"
     "eq:diffie–hellman-1"
     "eq:diffie–hellman-2"
     "sec:elgamal-cryptosystem"
     "fig:basic-elgamal-encryption"
     "fig:basic-elgamal-public-key-encry-algo"
     "eq:elgamal-encryption-1"
     "eq:elgamal-encryption-2"
     "eq:elgamal-encryption-3"
     "eq:elgamal-encryption-4"
     "eq:elgamal-encryption-5"
     "eq:elgamal-encryption-6"
     "fig:attack-power-of-two")
    (TeX-run-style-hooks
     "algorithmic"
     "amssymb"
     "amsmath"
     ""
     "latex2e"
     "beamer10"
     "beamer"
     "hyperref=true")))

