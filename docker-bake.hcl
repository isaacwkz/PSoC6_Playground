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
        "first_project",
    ]
}

target "first_project" {
    dockerfile = "docker/Dockerfile.first_project"
    cache-from = ["type=local,src=${CACHE}/psoc6_first_project-cache"]
    cache-to   = ["type=local,mode=max,dest=${CACHE}/psoc6_first_project-cache"]
    output     = ["${DEST}/First_Project"]
}