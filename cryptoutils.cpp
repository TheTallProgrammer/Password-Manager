#include "cryptoUtils.h"
#include <QCryptographicHash>
#include <QRandomGenerator>

// Generates a shorter, more user-friendly key
QString CryptoUtils::generateShortKey(int length) {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString randomString;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        randomString.append(possibleCharacters.at(index));
    }
    return randomString;
}

// Generates a key using the cipher key and a specified length
QByteArray CryptoUtils::generateKey(const QString &cipherKey, int keyLength) {
    QByteArray combinedKey = cipherKey.toUtf8();

    // Hash the combined key to generate a fixed-length key
    QByteArray hashedKey = QCryptographicHash::hash(combinedKey, QCryptographicHash::Sha256);

    // Trim the hashed key to the desired key length
    if (keyLength < hashedKey.size()) {
        hashedKey = hashedKey.left(keyLength);
    }

    return hashedKey;
}

// Encrypts data using a XOR operation with the generated key
QByteArray CryptoUtils::encryptData(const QByteArray &data, const QString &cipherKey, int keyLength) {
    QByteArray key = generateKey(cipherKey, keyLength);
    QByteArray result;

    for (int i = 0; i < data.size(); ++i) {
        result.append(data[i] ^ key[i % key.size()]);
    }

    return result;
}

// Decrypts data using the same XOR operation with the generated key
QByteArray CryptoUtils::decryptData(const QByteArray &encryptedData, const QString &cipherKey, int keyLength) {
    return encryptData(encryptedData, cipherKey, keyLength); // XOR decryption is the same as encryption
}

// Hashes the data using a SHA256 hash function with optional salt
QByteArray CryptoUtils::hashData(const QByteArray &data, const QByteArray &salt) {
    QByteArray saltedData = data + salt;
    return QCryptographicHash::hash(saltedData, QCryptographicHash::Sha256);
}
