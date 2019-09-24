Pod::Spec.new do |s|
s.name = "DesayBluetooth"
s.version = "2.4.4"
s.summary = "DesayBluetooth is a Bluetooth library"
s.license = "MIT"
s.authors = {"Desay"=>"jaysonj@163.com"}
s.homepage = "https://github.com/jaysonjh/DesayBluetooth"
s.frameworks = "CoreBluetooth"
s.libraries = "z"

s.platform     = :ios
s.ios.deployment_target = "9.0"
s.requires_arc = true
s.source       = { :git => "git@github.com:jaysonjh/DesayBluetooth.git", :tag => s.version.to_s }

s.vendored_framework   = '*.framework'
# Nordic iOS DFULibrary
s.dependency 'iOSDFULibrary', '~>4.5'
s.swift_versions = ['4.2','5.0']
end