import UIKit

class ClearNumberPad : GenericPinPadCell {

    override var style: PinPadStyle {
        get { return .clear }
        set {}
    }

    override var label: UILabel {
        get { return cutoutLabel }
        set {}
    }

    private let cutoutLabel = CutoutLabel(font: .customBody(size: 28.0))

    override func setAppearance() {
        label.textColor = .clear
        if isHighlighted {
            backgroundColor = .transparentBlack
        } else {
            if text == "" {
                backgroundColor = .clear
                imageView.tintColor = .white
                imageView.backgroundColor = .clear
                label.isHidden = true
                masks.forEach {
                    $0.isHidden = false
                }
            } else if let text = text, PinPadViewController.SpecialKeys(rawValue: text) != nil {
                backgroundColor = .clear
                imageView.tintColor = .darkBackground
                imageView.backgroundColor = .clear
                label.isHidden = true
                masks.forEach {
                    $0.isHidden = false
                }
            } else {
                backgroundColor = .clear
                masks.forEach {
                    $0.isHidden = true
                }
            }
        }
    }
}
