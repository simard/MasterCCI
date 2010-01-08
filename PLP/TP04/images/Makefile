PNG=$(wildcard *.png)
EPS=$(PNG:.png=.eps)

all: $(EPS)
	@echo --- IMAGES TRAITÉES ---

%.eps: %.png
	convert $< eps:->$@

clean:
	@echo --- RIEN À ENLEVER ---

proper:
	@rm -f *.eps
