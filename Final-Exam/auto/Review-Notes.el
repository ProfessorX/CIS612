(TeX-add-style-hook "Review-Notes"
 (lambda ()
    (LaTeX-add-labels
     "algo:rc4-keystream-byte"
     "algo:tea-encryption"
     "algo:keygen-for-rsa-encrypt")
    (TeX-run-style-hooks
     "algorithmic"
     "algorithm"
     "graphicx"
     "geometry"
     "margin=10mm"
     "amssymb"
     "amsmath"
     ""
     "latex2e"
     "art10"
     "article"
     "twocolumn")))

