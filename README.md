# authKi - Open Source Crypto Authentication USB Dongle
**Align center:**
<p align="center" width="80%">
    <img width="33%" src="[https://i.stack.imgur.com/RJj4x.png](https://github.com/Irdroid/authKi/blob/main/Hardware/Pictures/PB170081-1%20(Small).jpg)"> 
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

## Secure Boot Support:

- Full ECDSA code signature validation, optional stored digest/signature
- Optional communication key disablement prior to secure boot
- Encryption/Authentication for messages to prevent on-board attacks
- Internal High-Quality NIST SP 800-90A/B/C Random Number Generator (RNG)

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
