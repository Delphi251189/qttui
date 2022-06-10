#ifndef QTUILINEEDIT_H
#define QTUILINEEDIT_H

#include "qtuiwidget.h"


class  QTuiLineEdit : public QTuiWidget
{
    Q_OBJECT
    /*
    Q_PROPERTY(QString inputMask READ inputMask WRITE setInputMask)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged USER true)
    Q_PROPERTY(int maxLength READ maxLength WRITE setMaxLength)
    Q_PROPERTY(EchoMode echoMode READ echoMode WRITE setEchoMode)
    Q_PROPERTY(QString displayText READ displayText)
    Q_PROPERTY(int cursorPosition READ cursorPosition WRITE setCursorPosition)
    Q_PROPERTY(Qt::Alignment alignment READ alignment WRITE setAlignment)
    Q_PROPERTY(bool modified READ isModified WRITE setModified DESIGNABLE false)
    Q_PROPERTY(bool hasSelectedText READ hasSelectedText)
    Q_PROPERTY(QString selectedText READ selectedText)
    Q_PROPERTY(bool readOnly READ isReadOnly WRITE setReadOnly)
    Q_PROPERTY(bool undoAvailable READ isUndoAvailable)
    Q_PROPERTY(bool redoAvailable READ isRedoAvailable)
    Q_PROPERTY(bool acceptableInput READ hasAcceptableInput)
    Q_PROPERTY(QString placeholderText READ placeholderText WRITE setPlaceholderText)
    Q_PROPERTY(bool clearButtonEnabled READ isClearButtonEnabled WRITE setClearButtonEnabled)
*/
public:
    enum ActionPosition {
        LeadingPosition,
        TrailingPosition
    };
    Q_ENUM(ActionPosition)

    explicit QTuiLineEdit(QTuiWidget *parent = Q_NULLPTR);
    explicit QTuiLineEdit(const QString &, QTuiWidget *parent = Q_NULLPTR);
    virtual ~QTuiLineEdit();

    QString text() const;

    QString displayText() const;

    QString placeholderText() const;
    void setPlaceholderText(const QString &);

    int maxLength() const;
    void setMaxLength(int);

    void setFrame(bool);
    bool hasFrame() const;

    void setClearButtonEnabled(bool enable);
    bool isClearButtonEnabled() const;

    enum EchoMode { Normal, NoEcho, Password, PasswordEchoOnEdit };
    Q_ENUM(EchoMode)
    EchoMode echoMode() const;
    void setEchoMode(EchoMode);

    bool isReadOnly() const;
    void setReadOnly(bool);

    int cursorPosition() const;
    void setCursorPosition(int);
    int cursorPositionAt(const QPoint &pos);

    void setAlignment(Qt::Alignment flag);
    Qt::Alignment alignment() const;

    void cursorForward(bool mark, int steps = 1);
    void cursorBackward(bool mark, int steps = 1);
    void cursorWordForward(bool mark);
    void cursorWordBackward(bool mark);
    void backspace();
    void del();
    void home(bool mark);
    void end(bool mark);

    bool isModified() const;
    void setModified(bool);

    void setSelection(int, int);
    bool hasSelectedText() const;
    QString selectedText() const;
    int selectionStart() const;

    bool isUndoAvailable() const;
    bool isRedoAvailable() const;

    void setDragEnabled(bool b);
    bool dragEnabled() const;

    void setCursorMoveStyle(Qt::CursorMoveStyle style);
    Qt::CursorMoveStyle cursorMoveStyle() const;

    QString inputMask() const;
    void setInputMask(const QString &inputMask);
    bool hasAcceptableInput() const;

    void setTextMargins(int left, int top, int right, int bottom);
    void setTextMargins(const QMargins &margins);
    void getTextMargins(int *left, int *top, int *right, int *bottom) const;
    QMargins textMargins() const;


//public slots:
//    void setText(const QString &);
//    void clear();
//    void selectAll();
//    void undo();
//    void redo();
//    void cut();
//    void copy() const;
//    void paste();
public:
    void deselect();
    void insert(const QString &);
signals:
    void textChanged(const QString &);
    void textEdited(const QString &);
    void cursorPositionChanged(int, int);
    void returnPressed();
    void editingFinished();
    void selectionChanged();
protected:
    QRect cursorRect() const;

public:

private:

};


#endif // QTuiLineEdit_H
