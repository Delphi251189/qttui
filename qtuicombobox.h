#ifndef QTUICOMBOBOX_H
#define QTUICOMBOBOX_H

#include "qtuiwidget.h"

struct QTuiComboBoxPrivate;
class QTuiComboBox : public QTuiWidget
{
    Q_OBJECT
    Q_PROPERTY(bool editable READ isEditable WRITE setEditable)
    Q_PROPERTY(int count READ count)
    Q_PROPERTY(QString currentText READ currentText WRITE setCurrentText NOTIFY currentTextChanged USER true)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(QVariant currentData READ currentData)
    Q_PROPERTY(int maxVisibleItems READ maxVisibleItems WRITE setMaxVisibleItems)
    Q_PROPERTY(int maxCount READ maxCount WRITE setMaxCount)
    //Q_PROPERTY(InsertPolicy insertPolicy READ insertPolicy WRITE setInsertPolicy)
    //Q_PROPERTY(int minimumContentsLength READ minimumContentsLength WRITE setMinimumContentsLength)
    //Q_PROPERTY(bool duplicatesEnabled READ duplicatesEnabled WRITE setDuplicatesEnabled)
public:
    explicit QTuiComboBox(QTuiWidget *parent = Q_NULLPTR);
    virtual ~QTuiComboBox();

    int maxVisibleItems() const;
    void setMaxVisibleItems(int maxItems);

    int count() const;
    void setMaxCount(int max);
    int maxCount() const;
    bool duplicatesEnabled() const;
    void setDuplicatesEnabled(bool enable);
    inline int findText(const QString &text, Qt::MatchFlags flags = static_cast<Qt::MatchFlags>(Qt::MatchExactly|Qt::MatchCaseSensitive)) const;
    int findData(const QVariant &data, int role = Qt::UserRole, Qt::MatchFlags flags = static_cast<Qt::MatchFlags>(Qt::MatchExactly|Qt::MatchCaseSensitive)) const;
    enum InsertPolicy {
        NoInsert,
        InsertAtTop,
        InsertAtCurrent,
        InsertAtBottom,
        InsertAfterCurrent,
        InsertBeforeCurrent,
        InsertAlphabetically
    };
    // Q_ENUM(InsertPolicy)

    InsertPolicy insertPolicy() const;
    void setInsertPolicy(InsertPolicy policy);
    int minimumContentsLength() const;
    void setMinimumContentsLength(int characters);
    QSize iconSize() const;
    void setIconSize(const QSize &size);
    bool isEditable() const;
    void setEditable(bool editable);
    int currentIndex() const;
    QString currentText() const;
    QVariant currentData(int role = Qt::UserRole) const;
    QString itemText(int index) const;
    QVariant itemData(int index, int role = Qt::UserRole) const;

    void addItem(const QString &text, const QVariant &userData = QVariant());
    void addItems(const QStringList &texts) { insertItems(count(), texts); }
    void insertItem(int index, const QString &text, const QVariant &userData = QVariant());
    void insertItem(int index, const QIcon &icon, const QString &text, const QVariant &userData = QVariant());
    void insertItems(int index, const QStringList &texts);
    void insertSeparator(int index);
    void removeItem(int index);
    void setItemText(int index, const QString &text);
    void setItemData(int index, const QVariant &value, int role = Qt::UserRole);
public slots:
    void clear();
    void clearEditText();
    void setEditText(const QString &text);
    void setCurrentIndex(int index);
    void setCurrentText(const QString &text);
    void hidePopup();
    void showPopup();

signals:
    void editTextChanged(const QString &);
    void activated(int index);
    void activated(const QString &);
    void highlighted(int index);
    void highlighted(const QString &);
    void currentIndexChanged(int index);
    void currentIndexChanged(const QString &);
    void currentTextChanged(const QString &);
protected:
    QTuiComboBoxPrivate *d;

};


#endif // QTUICOMBOBOX_H

