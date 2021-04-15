	.arch msp430g2553
	.p2align 1
	.text

	.extern red_on
	.extern green_on
	


	.global turn_off
	
turn_off:
	mov #0, &red_on
	mov #0, &green_on
	mov #1, &led_changed
	call #led_update
	mov #1, r13
	pop r13
