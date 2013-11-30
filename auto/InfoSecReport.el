(TeX-add-style-hook "InfoSecReport"
 (lambda ()
    (LaTeX-add-bibliographies
     "IEEEabrv"
     "Reference")
    (LaTeX-add-labels
     "sec:introduction"
     "sec:publ-key-crypt"
     "sec:rsa-cryptosystem"
     "sec:el-gamal-crypt"
     "sec:implementation")
    (TeX-run-style-hooks
     "hyperref"
     "url"
     "stfloats"
     "fixltx2e"
     "font=footnotesize"
     "subfig"
     "textfont=sf"
     "labelfont=sf"
     "font=normalsize"
     "caption=false"
     "eqparbox"
     "mdwtab"
     "mdwmath"
     "array"
     "algorithmic"
     "amsmath"
     "cmex10"
     "dvips"
     "graphicx"
     "pdftex"
     ""
     "cite"
     "nocompress"
     "latex2e"
     "IEEEtran12"
     "IEEEtran"
     "compsoc"
     "journal"
     "12pt")))

