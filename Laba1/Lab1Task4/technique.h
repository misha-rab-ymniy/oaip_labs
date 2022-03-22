#ifndef TECHNIQUE_H
#define TECHNIQUE_H

#include <QString>

class Technique
{
private:
    QString type;
    QString firm;
    QString model;
    int price;
    bool isAval;
public:
    Technique();
    const QString &getType() const;
    void setType(const QString &newType);
    const QString &getFirm() const;
    void setFirm(const QString &newFirm);
    const QString &getModel() const;
    void setModel(const QString &newModel);
    int getPrice() const;
    void setPrice(int newPrice);
    bool getIsAval() const;
    void setIsAval(bool newIsAval);
    QString toString();
};

#endif // TECHNIQUE_H
