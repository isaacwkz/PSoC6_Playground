variable "HOME" {
    default = "$HOME"
}

variable "CACHE" {
    default = "${HOME}/tmp"
}

variable "DEST" {
    default = "./"
}

group "default" {
    targets = [
        "tx_usb",
        "radar",
    ]
}

target "tx_usb" {
    dockerfile = "docker/Dockerfile.tx_usb"
    cache-from = ["type=local,src=${CACHE}/psoc6_tx_usb-cache"]
    cache-to   = ["type=local,mode=max,dest=${CACHE}/psoc6_tx_usb-cache"]
    output     = ["${DEST}/ThreadX_USB"]
}

target "radar" {
    dockerfile = "docker/Dockerfile.radar"
    cache-from = ["type=local,src=${CACHE}/psoc6_radar-cache"]
    cache-to   = ["type=local,mode=max,dest=${CACHE}/psoc6_radar-cache"]
    output     = ["${DEST}/Radar"]
}