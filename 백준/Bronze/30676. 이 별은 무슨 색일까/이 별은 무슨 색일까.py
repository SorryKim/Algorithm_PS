def star_color(wavelength):
    if 620 <= wavelength <= 780:
        return "Red"
    elif 590 <= wavelength < 620:
        return "Orange"
    elif 570 <= wavelength < 590:
        return "Yellow"
    elif 495 <= wavelength < 570:
        return "Green"
    elif 450 <= wavelength < 495:
        return "Blue"
    elif 425 <= wavelength < 450:
        return "Indigo"
    elif 380 <= wavelength < 425:
        return "Violet"

n = int(input())
print(star_color(n))
