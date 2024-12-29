import 'package:dart_ffi_mac_ui/dart_ffi_mac_ui.dart';
import 'package:test/test.dart';
import 'dart:io' as io;
//import 'dart:isolate'; 

void main() async {
  test('check platform is MacOS', () {
    expect(io.Platform.isMacOS, true);
  });
  test('test on current thread', () {
    expect(ffi_sum_on_current_thread(1, 2), 3);
  });
  test('test on ui thread', () async {
    print('trying invoke on ui thread...');
    expect(ffi_sum_on_ui_thread(1, 2), 3);;
    //expect(await Isolate.run(() => ffi_sum_on_ui_thread(1, 2)), 3);
  });
}