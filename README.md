```javascript
<a href="https://your-url" class="github-corner" aria-label="View source on GitHub"><svg width="80" height="80" viewBox="0 0 250 250" style="fill:#151513; color:#fff; position: absolute; top: 0; border: 0; right: 0;" aria-hidden="true"><path d="M0,0 L115,115 L130,115 L142,142 L250,250 L250,0 Z"></path><path d="M128.3,109.0 C113.8,99.7 119.0,89.6 119.0,89.6 C122.0,82.7 120.5,78.6 120.5,78.6 C119.2,72.0 123.4,76.3 123.4,76.3 C127.3,80.9 125.5,87.3 125.5,87.3 C122.9,97.6 130.6,101.9 134.4,103.2" fill="currentColor" style="transform-origin: 130px 106px;" class="octo-arm"></path><path d="M115.0,115.0 C114.9,115.1 118.7,116.5 119.8,115.4 L133.7,101.6 C136.9,99.2 139.9,98.4 142.2,98.6 C133.8,88.0 127.5,74.4 143.8,58.0 C148.5,53.4 154.0,51.2 159.7,51.0 C160.3,49.4 163.2,43.6 171.4,40.1 C171.4,40.1 176.1,42.5 178.8,56.2 C183.1,58.6 187.2,61.8 190.9,65.4 C194.5,69.0 197.7,73.2 200.1,77.6 C213.8,80.2 216.3,84.9 216.3,84.9 C212.7,93.1 206.9,96.0 205.4,96.6 C205.1,102.4 203.0,107.8 198.3,112.5 C181.9,128.9 168.3,122.5 157.7,114.1 C157.9,116.9 156.7,120.9 152.7,124.9 L141.0,136.5 C139.8,137.7 141.6,141.9 141.8,141.8 Z" fill="currentColor" class="octo-body"></path></svg></a><style>.github-corner:hover .octo-arm{animation:octocat-wave 560ms ease-in-out}@keyframes octocat-wave{0%,100%{transform:rotate(0)}20%,60%{transform:rotate(-25deg)}40%,80%{transform:rotate(10deg)}}@media (max-width:500px){.github-corner:hover .octo-arm{animation:none}.github-corner .octo-arm{animation:octocat-wave 560ms ease-in-out}}</style>
```
# Open Source Crypto Authentication USB Dongle
<p align="center" width="40%">
    <img width="50%" src="https://raw.githubusercontent.com/Irdroid/authKi/683cc1a6c868871baae747778073e68e58a7a1d4/Hardware/Pictures/PB170081-1%20(Small).jpg"> 
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

### 1. Clone this repository: 
```javascript
git clone --recurse-submodules https://github.com/Irdroid/authKi.git
```
This will checkout the repo and all submodules. You can then compile and install the cryptoauthlib library localted in /Software/Cryptoauthlib/
**You can also download a pre-built release package from the "releases" section above**.
    
### 2.  Install OpenSC:
```javascript
sudo apt install opensc
```
### 4. Set **udev rules** 
(If you are compiling from source | **You can skip this step if you are installing a prebuilt cryptoauthlib package from the releases section above**), so that the authKi will always get the same i2c interface number as a sysfs entry 
    - Create a file in /etc/udev/rules.d/11-tiny.rules with the content : 
```javascript 
   ACTION=="add|change", SUBSYSTEM=="i2c-dev", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="c631", SYMLINK+="i2c-20"
```
### 5. Create / Edit /var/lib/cryptoauthlib/0.conf
Add the following content ( If you are compiling / installing from source)
```javascript 

# Reserved Configuration for a device
# The objects in this file will be created and marked as undeletable
# These are processed in order. Configuration parameters must be comma
# delimited and may not contain spaces

# Set a label for this slot (optional) - will default to <slot>ABC so
# 0.conf will have a default label 00ABC
label = 00ABC

# Configure the device interface for an enabled HAL
# hid,i2c,<address>
# i2c,<address>,<bus>
# spi,<select_line>,<baud>
interface = i2c,6C,20

# Configure the device type - base part number (optional)
device = ATECC608B-TFLXTLS

#Configure open slots for additional pkcs11 objects (optional)
#freeslots = 1,2,3
freeslots = 2,3,4,5
# Manually configure keys into device locations (slots/handles)

# Slot 0 is the primary private key
object = private,device,0
#object = private,device,0
# Slot 15 is a public key
#object = public,root,15
```
### 6. Configure SSH:
Edit /home/your_user/.ssh/config and add:
```javascript 
PKCS11Provider /usr/lib/libcryptoauth.so
```
The above will configure the cryptoauthlib as a PKCS11 Provider for All SSH connections. To configure the use of the library and the authki for specific connection add the following (for example for GitHub authentication in ./ssh/config)

```javascript 
Host github.com
 PKCS11Provider /usr/lib/libcryptoauth.so
 Port 22
 User youruser
```
This way if you have multipl authentication dongles, and/or smartcards you can specify which connection will use the relevant authentication key/smartcard


### 7. Export the ECDSA Public key from the authKi
```javascript
ssh-keygen -D /usr/lib/libcryptoauth.so
```
### 8. Use the authKi for SSH Authentication / Github GIT+SSH
The above command will print your public ECDSA key in the console, the key is suitable for usage in a remote server authorized_keys file or with Github
After putting the public key into a remote system , you can ssh into it, while your authKi is inserted in your computer.

### 9 Configuring authKi for use with the Eclet

1. Compile and install the Ecltet, the source is located in /Software/Eclet

#### random
```bash
eclet random
62F95589AC76855A8F9204C9C6B8B85F06E6477D17C3888266AEE8E1CBD65319
```
#### serial-num
```bash
eclet serial-num
0123XXXXXXXXXXXXEE
```
X's indicate the unique serial number.

#### get-pub
```bash
eclet get-pub
04EED1CB629CF87F8BF6419986F990B92EA3DFA14CDAF70EB3E8DA8F9C9504DBC5B040D6480E88F895E9E1D4477970329B060450C80E1816EFED7B0FA49868CAEB
```
One can get the public key at any time calling the command get-pub. In case the public key of a specific slot has to be called use the parameter -k.

```bash
eclet get-pub -k 0
04EED1CB629CF87F8BF6419986F990B92EA3DFA14CDAF70EB3E8DA8F9C9504DBC5B040D6480E88F895E9E1D4477970329B060450C80E1816EFED7B0FA49868CAEB
```

#### sign
```bash
eclet sign -f ChangeLog
3BAEB5705D8765B34B389F1768BAC783FCA786AB64A760D10DD133C86E5892A7A790E424C8E1540551C99FBE4F9F531B504A6004F08F3E0D4E42E96BBDE5C179
```

Performs an ECDSA signature. Data can be specified as a file with the `-f` option or passed via `stdin`. The data will be SHA256 hashed prior to signing. The result is the signature in the format: R + S.

#### verify
```bash
eclet verify -f ChangeLog --signature C650D1A30194AD68F60F40C321FB084F6177BEDAC74D0F0C276ED35B00249AC8CF3E96FB7AB14AA48223FBA2E5DD9BCAE232BF963755C42F8FD9BD77FC145D41 --public-key 049B4A517704E16F3C99C6973E29F882EAF840DCD125C725C9552148A74349EB77BECB37AA2DB8056BAF0E236F6DCFEC2C5A9A0F23CEFD8A9DC1F4693718E725D2
```

Verifies an ECDSA signature using the device. You specify the data (which will be SHA256 hashed), the signature (R+S), and the public key (0x04+X+Y). Returns a `0` exit code on success.

#### offline-verify-sign
```bash
eclet offline-verify-sign -f ChangeLog --signature C650D1A30194AD68F60F40C321FB084F6177BEDAC74D0F0C276ED35B00249AC8CF3E96FB7AB14AA48223FBA2E5DD9BCAE232BF963755C42F8FD9BD77FC145D41 --public-key 049B4A517704E16F3C99C6973E29F882EAF840DCD125C725C9552148A74349EB77BECB37AA2DB8056BAF0E236F6DCFEC2C5A9A0F23CEFD8A9DC1F4693718E725D2
```
### 10. There are other examples in the cryptoauthlib directory for other functionalities such as AES128 enclode/decode, SHA-256 tests and examples and more. 
