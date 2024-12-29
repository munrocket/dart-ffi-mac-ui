import 'package:native_assets_cli/native_assets_cli.dart';
import 'package:native_toolchain_c/native_toolchain_c.dart';

void main(List<String> args) async {
  await build(args, (config, output) async {
    final cbuilder = CBuilder.library(
      name: 'dart_ffi_mac_ui',
      assetName: 'dart_ffi_mac_ui.dart',
      sources: [
        'src/dart_ffi_mac_ui.m'
      ],
      frameworks: [
        'Foundation',
        'Cocoa',
        'Metal',
        'CoreVideo',
      ],
      language: Language.objectiveC,
    );
    await cbuilder.run(
      config: config,
      output: output,
      logger: null,
    );
  });
}