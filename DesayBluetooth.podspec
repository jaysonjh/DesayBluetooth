Pod::Spec.new do |s|
  s.name = "DesayBluetooth"
  s.version = "1.1.13"
  s.summary = "DesayBluetooth is a Bluetooth library"
  s.license = "MIT"
  s.authors = {"Desay"=>"454040106@qq.com"}
  s.homepage = "http://59.33.252.108/Framework/dsble"
  s.frameworks = "CoreBluetooth",'DesayBluetooth'
  s.libraries = "z"

  s.platform     = :ios
  s.ios.deployment_target = "8.0"
  s.requires_arc = true
  s.source       = { :git => "ssh://git@59.33.252.108:122/Framework/dsble.git", :tag => s.version.to_s }


  s.vendored_framework   = '*.framework'

end
