#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <QString>
#include <QByteArray>

class CryptoUtils {
public:
    // Generates a shorter, more user-friendly key
    static QString generateShortKey(int length);

    // Generates a key using the cipher key
    static QByteArray generateKey(const QString &cipherKey);

    // Encrypts data using a XOR operation with the generated key
    static QByteArray encryptData(const QByteArray &data, const QString &cipherKey);

    // Decrypts data using the same XOR operation with the generated key
    static QByteArray decryptData(const QByteArray &encryptedData, const QString &cipherKey);

    // Hashes the data using a SHA256 hash function with optional salt
    static QByteArray hashData(const QByteArray &data, const QByteArray &salt = QByteArray());
};

#endif // CRYPTOUTILS_H
