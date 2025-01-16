platform :ios, '14.0'

target 'SVGKit-iOS' do
    project 'SVGKit-iOS.xcodeproj'
    pod 'CocoaLumberjack', '3.7.4'
end

#Override the deployment targets of all pods
post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |config|
            config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '14.0'
            config.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
            config.build_settings['ENABLE_USER_SCRIPT_SANDBOXING'] = 'NO'
    
            # Activate VisionOS support for all Pods                                                                        
            # https://github.com/CocoaPods/CocoaPods/issues/12094                                                           
            config.build_settings['XROS_DEPLOYMENT_TARGET'] = '2.0'
            config.build_settings['SUPPORTED_PLATFORMS'] = 'iphoneos iphonesimulator xros xrsimulator' # Includes VisionOS (xros) and its simulator (xrsimulator)                                                                                  
            config.build_settings['TARGETED_DEVICE_FAMILY'] = '1,2,7' # Incorporate device family '7' for VisionOS          
  
        end
    end
end
