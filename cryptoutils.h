#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <QByteArray>
#include <QString>

class CryptoUtils {
public:
    // Generates a shorter, user-friendly key of specified length
    static QString generateShortKey(int length);

    // Generates a machine-specific key using the MAC address and a cipher key with specified key length
    static QByteArray generateKey(const QString &cipherKey, int keyLength = 32);

    // Encrypts data using a XOR operation with the generated key
    static QByteArray encryptData(const QByteArray &data, const QString &cipherKey, int keyLength = 32);

    // Decrypts data using the same XOR operation with the generated key
    static QByteArray decryptData(const QByteArray &encryptedData, const QString &cipherKey, int keyLength = 32);

    // Hashes the data using a SHA256 hash function with or without salt
    static QByteArray hashData(const QByteArray &data, const QByteArray &salt = QByteArray());
};

#endif // CRYPTOUTILS_H
