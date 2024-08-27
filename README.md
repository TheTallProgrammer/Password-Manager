
<h1 align="center">🔒 Falkenberg's Password Manager (Beta)</h1>
<div align="center">
    <img src="icon.png" alt="App Icon" width="150" />
</div>


**Falkenberg's Password Manager** is a secure, lightweight, and 100% local password management solution designed for users who prioritize offline security. Operating entirely on your local machine, it ensures your passwords remain accessible even in the most challenging network conditions.

> **Note:** This application currently only works on Windows machines.

## 📑 Table of Contents

1. [Key Features](#-key-features)
    - [Purely Local & Secure](#1-purely-local--secure)
    - [Robust Encryption & Hashing](#2-robust-encryption--hashing)
    - [Strong Password Generator](#3-strong-password-generator)
    - [Simple & Intuitive Management Interface](#4-simple--intuitive-management-interface)
        - [Adding Passwords](#adding-passwords)
    - [Flexible Import/Export Options](#5-flexible-importexport-options)
        - [Exporting Your Passwords](#exporting-your-passwords)
        - [Importing Your Passwords](#importing-your-passwords)
    - [Security Features & Customization](#6-security-features--customization)
2. [Beta Release Notice](#-beta-release-notice)


## 🌟 Key Features

### 1. Purely Local & Secure

- **Offline Operation:** All data is stored locally on your device—no cloud storage, no remote breaches.
- **Advanced Encryption:** Uses a custom XOR-based encryption algorithm paired with a unique cipher key that you generate or customize.
  
### 2. Robust Encryption & Hashing

Falkenberg's Password Manager leverages industry-standard encryption techniques to keep your data secure:

- **🔑 Key Generation:** Your cipher key is hashed using SHA256, creating a robust 256-bit key that is nearly impossible to crack.
- **🔒 Encryption:** Passwords are encrypted using a XOR operation, ensuring that decryption without the correct key is nearly impossible.
- **🔑 Hashing:** Login passwords are securely hashed with SHA256, optionally salted, and stored separately from your encrypted passwords.
- **🔐 Unlimited Cipher Keys:** Use multiple cipher keys for different sets of passwords, enhancing security through compartmentalization.

<div align="center"> <img src="hashDemo.gif" alt="Encryption & Hashing Demo" width="100%" /> </div>

### 3. 🔧 Strong Password Generator

Create highly secure passwords using true randomization:

- **Customizable:** Set the length, complexity, and character types to generate passwords that meet your specific needs.
- **Random & Strong:** Ensures your passwords are truly random and extremely difficult to crack.

<div align="center"> <img src="genDemo.gif" alt="Password Generator Demo" width="80%" /> </div>

### 4. 🛠️ Simple & Intuitive Management Interface

Managing your passwords is straightforward and hassle-free:

- **No Clutter:** A clean interface with essential features easily accessible—no hidden menus or complicated settings.
- **Streamlined Workflow:** Six simple buttons to manage your passwords, plus an always-visible logout button.
- **Dark Theme:** Switch to a dark theme easily with a top-bar option—no need to dig through settings.

<div align="center"> <img src="viewPasswordsDemo.gif" alt="Password Management Demo" width="80%" /> </div>

#### Adding Passwords

- **🆔 Pass ID:** A unique identifier for each password entry.
- **👤 User:** The username or email associated with the account.
- **🔑 Pass:** The actual password, securely encrypted.
- **📝 Thought Bank:** A notes section for security questions, hints, or additional context.

<div align="center"> <img src="addPasswordDemo.gif" alt="Adding Password Demo" width="80%" /> </div>

### 5. 📁 Flexible Import/Export Options

#### Exporting Your Passwords

- **Easy Backup:** Transfer your passwords across devices with an easy-to-use export function.
- **Raw Text Format:** Exported data is in raw text form for easy re-importing, but remember to handle these files securely since they are not encrypted.

<div align="center"> <img src="exportDemo.gif" alt="Export Demo" width="80%" /> </div>

#### Importing Your Passwords

- **Specific Format:** Import files must be JSON files created by Falkenberg's Password Manager, as they require a specific format.
- **Future Features:** Support for importing JSON files from other password managers is in development.

<div align="center"> <img src="importDemo.gif" alt="Import Demo" width="80%" /> </div>

### 6. 🛡️ Security Features & Customization

- **Hidden Keystrokes:** The login interface hides keystrokes as you type your password, offering enhanced security in public spaces.
	<div align="center"> <img src="loginDemo.gif" alt="Security Features Demo" width="80%" /> </div>
- **Delete All:** Instantly wipe all saved passwords for any used cipher key if you feel your system is compromised.
	<div align="center"> <img src="deleteAllDemo.gif" alt="Delete All Demo" width="80%" /> </div>
- **Theme Customization:** Choose from four unique themes: Nightshade, Sunset, Light, and Amethyst.
<div align="center"> <img src="themesDemo.gif" alt="Themes Demo" width="80%" /> </div>

---

## 🚀 Beta Release Notice

This version of Falkenberg's Password Manager is a beta release and represents my second major application as a college student, following my first project, Stock Contender. While every feature has been thoroughly tested, some bugs may still occur. 

> **Important:** This application is designed to function strictly offline—your data is never sent to the cloud, ensuring that there is no remote access. Future versions may include optional cloud features, primarily for password recovery, but local security will always be the core focus.

Your feedback is crucial for improving the application's reliability and performance. If you encounter any issues, please consider submitting a bug report.

