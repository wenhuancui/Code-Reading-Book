/* Generated by Together */

#ifndef DIALOGPEER_H
#define DIALOGPEER_H


namespace VCF{

/** @interface */
class APPKIT_API DialogPeer : public VCF::ControlPeer {
public:
	virtual ~DialogPeer(){};

	virtual Rect* getClientBounds() = 0;

	virtual void  setClientBounds( Rect* bounds ) = 0;

	virtual ModalReturnType showModal() = 0;

	virtual void show() = 0;

	virtual void close() = 0;

	virtual void setFrameStyle( const FrameStyleType& frameStyle ) = 0;

	virtual void setCaption( const String& caption ) = 0;

	virtual void showMessage( const String& message, const String& caption ) = 0;

	virtual ModalReturnType showMessage( const String& message, const String& caption, const MessageStyle& messageStyle ) = 0;
};

};
#endif //DIALOGPEER_H