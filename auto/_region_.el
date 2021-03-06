(TeX-add-style-hook "_region_"
 (lambda ()
    (LaTeX-add-bibliographies
     "IEEEabrv"
     "Reference")
    (LaTeX-add-environments
     "definition")
    (LaTeX-add-labels
     "sec:introduction"
     "sec:publ-key-crypt"
     "sec:rsa-cryptosystem"
     "sec:el-gamal-crypt"
     "sec:diff-hellm-probl"
     "sec:diff-hellm-probl-1"
     "sec:diff-hellm-probl-2"
     "eq:2"
     "eq:3"
     "fig:diffie-key-agreement"
     "sec:disctr-logar-probl"
     "def:Generalized-DLP"
     "eq:4"
     "sec:exhaustive-search"
     "sec:baby-step-giant"
     "fig:algo-baby-step-giant-step"
     "sec:poll-rho-algor-1"
     "eq:1"
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

