//////////////////////////////////////////////////////////////////////////////
// FFI library in STB style
//////////////////////////////////////////////////////////////////////////////

#ifndef DART_FFI_MAC_UI_H
#define DART_FFI_MAC_UI_H

#ifdef __cplusplus
extern "C" {
#endif

int ffi_sum_on_current_thread(int a, int b);
int ffi_sum_on_ui_thread(int a, int b);

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////////

#ifdef DART_FFI_MAC_UI_IMPLEMENTATION

#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>

int ffi_sum_on_current_thread(int a, int b) {
  return a + b;
}

int ffi_sum_on_ui_thread(int a, int b) {
  __block int result = 0;
  NSLog(@"before dispatch, result=%d", result);
  dispatch_async(dispatch_get_main_queue(), ^{
    result = a + b;
    NSLog(@"Dispatched to main thread, result=%d", result);
  });
  [NSThread sleepForTimeInterval: 3.0];
  NSLog(@"after dispatch, result=%d", result);
  return result;
}

#endif // DART_FFI_MAC_UI_IMPLEMENTATION
#endif // DART_FFI_MAC_UI_H