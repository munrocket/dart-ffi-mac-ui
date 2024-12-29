# Dart FFI MacOS UI thread

This repo shows Dart difficulties as a scripting language for graphics libraries on MacOS/iOS. Synchronous dispatch freezes, and asynchronous does not update values.

See [dart-lang/sdk#38315](https://github.com/dart-lang/sdk/issues/38315) for details.

## Build and test
dart --enable-experiment=native-assets test

## Update bindings
dart pub run ffigen
