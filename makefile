all:
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/juno	

	cp --recursive kyria qmk_firmware/keyboards/splitkb/kyria/keymaps/juno

	qmk flash

	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/juno


clean:
	git submodule deinit -f .
	git submodule update --init --recursive
