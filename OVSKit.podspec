Pod::Spec.new do |s|
s.name             = 'OVSKit'
s.version          = '0.0.1'
s.summary          = 'OVSKit offers a bunch of useful functions to facilitate developer work'
s.description      = <<-DESC
OVSKit offers a bunch of useful functions to facilitate developer work. Such as Network Request, Encryption/Decryption, Log and so on
DESC

s.homepage         = 'https://github.com/OpenVS/OVSKit'
s.license          = { :type => 'Customized', :text => 'https://www.openvs.org/license' }
s.author           = { 'OpenVS Team' => 'developer@thetopai.com' }
s.source           = { :git => 'https://github.com/OpenVS/OVSKit.git', :tag => s.version.to_s }
s.ios.deployment_target = '10.3'
s.source_files = 'OVSKit/**/*'
s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '$(inherited) -ObjC -lz' }
s.user_target_xcconfig  = { 'OTHER_LDFLAGS' => '$(inherited) -ObjC -lz' }
s.vendored_libraries = "libOVSKit.a"

# s.public_header_files = 'Pod/Classes/**/*.h'
# s.frameworks = 'UIKit', 'MapKit'
# s.dependency 'AFNetworking', '~> 2.3'
end
