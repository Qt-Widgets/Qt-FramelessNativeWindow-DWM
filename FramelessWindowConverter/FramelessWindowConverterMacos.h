#ifndef FRAMELESSWINDOWCONVERTERMACOS_H
#define FRAMELESSWINDOWCONVERTERMACOS_H

#ifdef __APPLE__

#include "FramelessWindowConverter_p.h"

#ifdef __OBJC__
@class NSWindow;
@class NSView;
@class NSButton;
#else
class NSWindow;
class NSView;
class NSButton;
#endif


namespace FWC
{

class FramelessWindowConverter;

class FramelessWindowConverterMacos : public FramelessWindowConverterPrivate
{
public:
    FramelessWindowConverterMacos(FramelessWindowConverter* q);
    bool filterNativeEvent(void *message, long *result) override;
    void minimizeWindow() override;
    void maximizeWindow() override;
    void restoreWindow() override;
    void closeWindow() override;
    void toggleFullscreen() override;
    void convertToFrameless() override;
    void convertToWindowWithFrame() override;

    void hideForTranslucency() override;
    void showForTranslucency() override;

private:
    NSView* nativeWidgetView;
    NSWindow* window;
    NSButton* fullScreenButton;
    NSButton* closeButton;
    NSButton* minimizeButton;
    bool isResizing = false;
    bool isMoving = false;
    FWC::FWCBorderHitTestResult currentBHTR = FWC::FWCBorderHitTestResult::NONE;
    FWCFloatingPoint startDiffCursorFrameLocs;
    void showCursorByHitResult(FWCBorderHitTestResult inBorderHitResult);
    void showAppropriateCursor();
    void resizeWindow(FWCFloatingPoint mouseLocationInWindow);
    void repositionTrafficLights();
};

}

#endif
#endif // FRAMELESSWINDOWCONVERTERMACOS_H
