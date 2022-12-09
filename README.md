# authKi - Open Source Crypto Authentication USB Dongle
<p align="center" width="40%">
    <img width="50%" src="https://github.com/Irdroid/authKi/blob/683cc1a6c868871baae747778073e68e58a7a1d4/Hardware/Pictures/PB170081-1%20(Small).jpg"> 
</p>

Irdroid authKi is a Open Source crypto Authentication USB Dongle, with built-in hardware support for Asymmetric Sign, Verify, Key Agreement for ECDSA - Elliptic curve digital signature algorithm, ECDSH - Elliptic Curve Diffie-Hellman and NIST Standard P256 Elliptic Curve Support,  thanks to the built-in Cryptographic Co-Processor with Secure Hardware-Based Key Storage - ATECC608B by Microchip.

USB 2.0 Interface to the host system with built-in drivers for GNU Linux, available drivers for MAC OS X and MS Windows. The authKi is targeted for use in GNU Linux but drivers for MAC OS X and MS Windows are also available. The device will enumerate on the host system as a I2C sysfs entey, which is then used by the Microchip’s cryptoauthlib for communication with the authKi dongle.

## Hardware support for:

- Asymmetric Sign, Verify, Key Agreement:
- ECDSA: FIPS186-3 Elliptic Curve Digital Signature
- ECDH: FIPS SP800-56A Elliptic Curve Diffie-Hellman
- NIST Standard P256 Elliptic Curve Support

## Symmetric Algorithms:

- SHA-256 & HMAC Hash including off-chip context save/restore
- AES-128: Encrypt/Decrypt, Galois Field Multiply for GCM

## Networking Key Management Support:

- Turnkey PRF/HKDF calculation for TLS 1.2 & 1.3
- Ephemeral key generation and key agreement in SRAM
- Small message encryption with keys entirely protected

## Software Support:

- Microchip’s Cryptoauthlib ( provides API and examples for interfacing with the authKi
- Eclet - a commandline tool to sign verify export public keys
- Other examples in the Irdroid’s authKi Github repository

## Example use:

- SSH authentication with a remote system via ECDSA keypairs ( your private key never leaves the hardware secure element e.g the AuthKi)
- ECDSA elliptic curve authentication with git / GitHub ( your private key never leaves the hardware secure element e.g the AuthKi)
- Digital Signature and Verification of files via Ellliptic Curve Algorithms (ECDSA/ECDSH)
- Developing Secure Crypto Wallets for Bitcoin / Ethereum
- Experimenting with the Microchip’s Cryptoauthlib for interfacing with the device.

## Where to start?

1. Clone this repository 
    - Issue git clone --recurse-submodules https://github.com/Irdroid/authKi.git
    - This will checkout the repo and all submodules. You can then compile and install the cryptoauthlib library localted in /Software/Cryptoauthlib.
    - You can also download a pre-built release package from the "releases" section above.
2. Set udev rules (If you are compiling from source | **You can skip this step if you are installing a prebuilt cryptoauthlib package from the releases section above**), so that the authKi will always get the same i2c interface number as a sysfs entry 
    - Create a file in /etc/udev/rules.d/11-tiny.rules with the content : ```javascript copyCodeBlock('ACTION=="add|change", SUBSYSTEM=="i2c-dev", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="c631", SYMLINK+="i2c-20"')```
4. 
