all:
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/juno	

	cp --recursive kyria qmk_firmware/keyboards/splitkb/kyria/keymaps/juno

	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/juno

	qmk flash

clean:
	git submodule deinit -f .
	git submodule update --init --recursive
