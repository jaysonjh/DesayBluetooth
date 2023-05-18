Pod::Spec.new do |s|
s.name = "DesayBluetooth"
s.version = "2.8.0"
s.summary = "DesayBluetooth is a Bluetooth library"
s.license = "MIT"
s.authors = {"Desay"=>"jaysonj@163.com"}
s.homepage = "https://github.com/jaysonjh/DesayBluetooth"
s.frameworks = "CoreBluetooth"
s.libraries = "z"

s.platform     = :ios
s.ios.deployment_target = "9.0"
s.requires_arc = true
s.source       = { :git => "https://github.com/jaysonjh/DesayBluetooth.git", :tag => s.version.to_s }

s.vendored_framework   = '*.framework'
# Nordic iOS DFULibrary
s.dependency 'iOSDFULibrary', '~>4.11'
s.swift_versions   = ['5.0', '5.1', '5.2', '5.3', '5.4', '5.5', '5.6']
# s.swift_version = '5.0'
##  Fix Pod trunk push command Failed with Xcode12
s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
## End Fix
end