all: quine_c quine_asm quine.ppm

quine_c: quine.c Makefile
	gcc $< -o $@
	strip -s -R.comment -R.note* $@

quine_asm: quine.asm Makefile
	nasm -f bin $< -o $@
	chmod +x $@

quine.ppm: quine_asm
	(echo "P6 9 6 255"; ./quine_asm; echo -n '..') > quine.ppm

clean:
	rm -f quine_c quine_asm quine.ppm

.PHONY: all test clean
.PONY: twilight sparkle
