import UIKit

struct MenuItem {
    let title: String
    let icon: UIImage?
    let accessoryText: (() -> String)?
    let callback: () -> Void

    init(title: String, icon: UIImage? = nil, accessoryText: (() -> String)? = nil, callback: @escaping () -> Void) {
        self.title = title
        self.icon = icon?.withRenderingMode(.alwaysTemplate)
        self.accessoryText = accessoryText
        self.callback = callback
    }
    
    init(title: String, icon: UIImage? = nil, subMenu: [MenuItem], rootNav: UINavigationController) {
        let subMenuVC = MenuViewController(items: subMenu, title: title)
        self.init(title: title, icon: icon, accessoryText: nil) {
            rootNav.pushViewController(subMenuVC, animated: true)
        }
    }
}
