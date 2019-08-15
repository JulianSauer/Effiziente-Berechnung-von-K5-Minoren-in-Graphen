workflow "Compile" {
  resolves = ["Compile PDF"]
  on = "push"
}

action "Compile PDF" {
  uses = "aergus/latex@latest"
  runs = "pdflatex main.tex"
}
