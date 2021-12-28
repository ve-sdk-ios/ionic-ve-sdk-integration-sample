//
//  EchoPlugin.swift
//  App
//
//  Created by Pavel Bulochkin on 22.12.21.
//

import Foundation
import Capacitor

@objc(EchoPlugin)
public class EchoPlugin: CAPPlugin {
    @objc func ve(_ call: CAPPluginCall) {
        DispatchQueue.main.async {
            let ourCustomViewController = UIStoryboard(name: "MainVE", bundle: nil).instantiateViewController(withIdentifier: "ViewControllerID") as! ViewController
            self.bridge?.viewController!.present(ourCustomViewController, animated: true, completion: nil)
        }
    }
}
