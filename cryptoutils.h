#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <QString>
#include <QByteArray>

class CryptoUtils {
public:
    // ====================
    // Public Methods
    // ====================
    static QString generateShortKey(int length); // Generates a shorter, more user-friendly key
    static QByteArray generateKey(const QString &cipherKey); // Generates a key using the cipher key
    static QByteArray encryptData(const QByteArray &data, const QString &cipherKey); // Encrypts data using a XOR operation with the generated key
    static QByteArray decryptData(const QByteArray &encryptedData, const QString &cipherKey); // Decrypts data using the same XOR operation with the generated key
    static QByteArray hashData(const QByteArray &data, const QByteArray &salt = QByteArray()); // Hashes the data using a SHA256 hash function with optional salt
};

#endif // CRYPTOUTILS_H
