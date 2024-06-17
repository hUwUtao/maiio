# the spinning game touch and stuff

this is a test stuff made with uno r3, to test the capabilities of the game. by following the protocol of lord sucareto at [mai2touch](https://github.com/Sucareto/Mai2Touch), i could connect with the game, through serial (really?).

but, it still lack of features, like HID for ring buttons, even not using mpr121 (in my situation, if you do have, please use sucareto), and using a piece of tinfoil to test the sensoring capability.

## idk, the hold is not right

the bad side is: i dont know how the game accept the signal the correct way, ofc undocumented, but i suspect the game really depend on the behaviour of mpr121, or not.

there is a few result from response of observation from "buddy" version, difference in the order and state it sent, which none of them seems to be correctly report the tinfoil output (the tinfoil output is consistent, or is it?, i observed with serial redundancy and debug led :\), serial have some latent as this point):

- a frame send 1 once there is state change, else send 0: the game touch and release instantly when touch foil and release foil
- a frame send 1 WHILE foil is touch, 0 WHILE release: while touching, the game touch and release instantly
- a frame send ONCE, of the state like above, wait until any state change, repeat: the game only touch and release instantly when touch down

thats all i could think of a way to simulate the input provided by mpr121, as i dont have these yet