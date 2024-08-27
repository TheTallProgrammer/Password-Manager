
# Falkenberg's Password Manager (Beta)

**Falkenberg's Password Manager** is a secure, lightweight, and 100% local password management solution designed for users who prioritize offline security. This application operates entirely on your local machine, eliminating the need for an internet connection and ensuring your passwords are accessible even in the most challenging network conditions.

**Please note:** This application currently only works on Windows machines.

![](icon.png)

## Features

### 1. Purely Local and Secure

Falkenberg's Password Manager operates entirely offline, with all password data stored locally on your device. This means there's no need to worry about remote breaches or connectivity issues. Every password is encrypted using a custom XOR-based encryption algorithm, paired with a unique cipher key generated specifically for you or one you create yourself.

### 2. Robust Encryption and Hashing

Falkenberg's Password Manager ensures your data is highly secure through a combination of strong encryption and hashing techniques:

- **Key Generation:** A unique cipher key is generated and hashed using the SHA256 algorithm, providing a consistent, 256-bit key that's extremely difficult to crack.
  
- **Encryption:** Passwords are encrypted using a XOR operation with your key, making decryption without the correct key nearly impossible. The key generation process is randomized, ensuring each key is unique and unpredictable.

- **Hashing:** Your login password is hashed with SHA256 and can include a salt for added security. This hash is stored separately from your encrypted passwords, furthering security.

- **Unlimited Cipher Keys:** Since the cipher key isn’t saved within the program, users have the flexibility to use multiple cipher keys for different sets of passwords. This means you can encrypt different groups of passwords with different keys, providing an extra layer of compartmentalization. The program is designed to decrypt data only with the exact cipher key used during encryption, making it impossible to decrypt data with a different key. This allows you to organize and secure your passwords based on different cipher keys if desired.

![Hashing Demo](hashDemo.gif)

### 3. Strong Password Generator

Falkenberg's Password Manager includes a powerful password generator that uses true randomization to create extremely strong passwords. You can customize parameters such as length, complexity, and character types to ensure your passwords meet the highest security standards.

![Password Generator Demo](genDemo.gif)

### 4. Simple and Intuitive Management Interface

Managing your passwords has never been easier. Falkenberg's Password Manager features a clean and straightforward retrieval and management page, allowing you to view, edit, copy, or delete your passwords with just a few clicks. This app is designed with simplicity in mind, avoiding the clutter and complexity found in many other password managers. What you see is what you get—there are no hidden features or convoluted menus. The interface is built around six simple buttons for managing your passwords, along with a clearly visible logout button. And if you prefer a dark theme, the option is conveniently located at the top of the app, eliminating the need to dig through settings.

![Password Management Demo](viewPasswordsDemo.gif)

#### Adding Passwords


Adding new passwords is a breeze. The process is streamlined, with each field clearly defined to make sure you know exactly what information goes where. Here’s a brief overview of each field:

- **Pass ID:** This is a unique identifier for each password entry. It helps you quickly locate and manage specific passwords when viewing all saved entries.
  
- **User:** This field is where you enter the username or email associated with the account for which the password is used.

- **Pass:** The actual password you want to store. This field is fully encrypted and secured, so you can be confident that your credentials are safe.

- **Thought Bank:** The Thought Bank is a notes section where you can add any details or information related to the password. Whether it’s security questions, hints, or additional context, this field helps keep everything you need in one place.

![Adding Password Demo](addPasswordDemo.gif)

### 5. Flexible Import/Export Options

#### Exporting Your Passwords

Need to transfer your passwords across devices? Falkenberg's Password Manager offers an easy-to-use export function, allowing you to back up your password data or move it to another device. The exported data is in raw text form, making it simple to re-import into the manager. However, please note that the exported data is not encrypted to maintain ease of access, so it’s important to handle these files securely.

![Export Demo](exportDemo.gif)

#### Importing Your Passwords

The import function lets you restore your passwords from a previously exported file. **Note:** The imported file must be a JSON file specifically created by Falkenberg's Password Manager, as it adheres to a unique format required by the application. While support for importing JSON files from other password managers is in development, it is not yet available. Make sure to keep your import files secure, as they contain sensitive data in a readable format.

![Import Demo](importDemo.gif)


### 6. Security Features and Customization

Falkenberg's Password Manager goes beyond just storing your passwords securely; it also ensures your login process is protected. The login interface hides keystrokes as you type your password, offering an additional layer of security, especially in public spaces where shoulder surfing might be a concern. This feature helps prevent unauthorized individuals from observing your password while you log in.

![Login Demo](loginDemo.gif)

If you ever feel your system is compromised, the application provides a "Delete All" feature to instantly wipe all saved passwords for any used cipher key. Additionally, you can change your login password if you suspect it's been compromised. 

![Delete All Demo](deleteAllDemo.gif)

Customize your experience with four unique themes: Nightshade, Sunset, Light, and Amethyst. Each theme is designed to provide a distinct look and feel, ensuring the application not only functions securely but also matches your aesthetic preferences.

![Themes Demo](themesDemo.gif)


## Beta Release Notice

This version of Falkenberg's Password Manager is a beta release and marks my second major application as a college student, following my first project, Stock Contender, which is available on my profile page. While I’ve thoroughly tested all features, some bugs may still occur. If you encounter any issues, please consider submitting a bug report.

Please note that this application is designed to be strictly local, meaning it does not require an internet connection to function, although it will still work if one is available. Your data is never sent to the cloud, and there is no way for others to gain access through remote means. Future versions may include optional cloud features, primarily for password recovery and similar functions, but the core focus on local security will remain unchanged.

Your feedback is invaluable for improving the application's reliability and performance in future updates.

