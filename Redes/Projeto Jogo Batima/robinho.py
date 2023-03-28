import pygame
from network import Network
import random
from moviepy.editor import VideoFileClip

width = 1280
height = 720
win = pygame.display.set_mode((width, height))
pygame.display.set_caption("Client")

# background
background = pygame.image.load("hahaha.png")
background = pygame.transform.scale(background, (width, height))

clientNumber = 0


def cutscene():
    clip = VideoFileClip("cuts.mp4")
    clip.preview()


def read_pos(str):  # string to tuple
    str = str.split(",")
    return int(str[0]), int(str[1]), int(str[2])


def make_pos(tup):  # tuple to string
    return str(tup[0]) + "," + str(tup[1]) + "," + str(tup[2])


def draw_background():
    win.blit(background, (0, 0))


class Player(pygame.sprite.Sprite):
    def __init__(self, x, y, pwidth, pheight, image):
        super().__init__()
        self.x = x
        self.y = y
        self.width = pwidth
        self.height = pheight
        self.image = image
        self.vel = 5

        self.health = 10

        self.last_shot = pygame.time.get_ticks()
        self.shoot_delay = 250
        self.shotCount = 0

        self.rect = self.image.get_rect()
        self.rect.center = ((pwidth // 2) + self.x, (pheight - 50) + self.y)

    def draw(self, win):
        win.blit(self.image, self.rect)

    def move(self):
        keys = pygame.key.get_pressed()

        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            self.x -= self.vel
        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            self.x += self.vel
        if keys[pygame.K_UP] or keys[pygame.K_w]:
            self.y -= self.vel
        if keys[pygame.K_DOWN] or keys[pygame.K_s]:
            self.y += self.vel

        now = pygame.time.get_ticks()
        if keys[pygame.K_SPACE] and now - self.last_shot > self.shoot_delay:
            self.last_shot = now
            bullet = Bullet(self.x, self.y, p1bullet_image)
            bulletsp1.append(bullet)
            self.shotCount += 1

        self.update()

    def update(self):
        self.rect = (self.x, self.y, self.width, self.height)

    def shot(self):
        bullet = Bullet(self.x, self.y, p2bullet_image)
        bulletsp2.append(bullet)
        pass


class Bullet(pygame.sprite.Sprite):
    def __init__(self, x, y, image):
        super().__init__()
        self.x = x
        self.y = y
        self.vel = 10

        self.image = image
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

    def draw(self):
        self.rect.y -= self.vel
        self.y -= self.vel
        win.blit(self.image, self.rect)


class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.original_image = pygame.image.load("coronga.png")
        self.image = pygame.transform.scale(self.original_image, (
            self.original_image.get_width() // 8, self.original_image.get_height() // 8))
        self.rect = self.image.get_rect()
        self.rect.x = random.randrange(width - self.rect.width)
        self.rect.y = random.randrange(-100, -40)
        self.vel = 1.5

    def draw(self):
        self.rect.y += self.vel
        win.blit(self.image, self.rect)
        if self.rect.top > height + 10:
            self.rect.x = random.randrange(width - self.rect.width)
            self.rect.y = random.randrange(-100, -40)
            self.vel = 1.5

    def die(self):
        self.rect.x = random.randrange(width - self.rect.width)
        self.rect.y = random.randrange(-100, -40)
        self.vel = 1.5


def redrawWindow(win, player, player2, enemies):
    win.fill((255, 255, 255))
    draw_background()
    player2.draw(win)
    player.draw(win)
    for enemy in enemies:
        enemy.draw()

    for bullet in bulletsp1:
        bullet.draw()
        if bullet.y < -10:
            bullet.kill()
            bulletsp1.remove(bullet)

    for bullet in bulletsp2:
        bullet.draw()
        if bullet.y < -10:
            bullet.kill()
            bulletsp2.remove(bullet)

    pygame.display.update()


def check_collisions(enemies, bulletss):
    for enemy in enemies:
        for bullet in bulletss:
            if enemy.rect.colliderect(bullet.rect):
                enemy.die()
                bulletss.remove(bullet)


# Batima
p1original_image = pygame.image.load("batima.png")
p1image = pygame.transform.scale(p1original_image, (
    p1original_image.get_width() // 6, p1original_image.get_height() // 6))

p1bullet_original_image = pygame.image.load("batarangue.png")
p1bullet_image = pygame.transform.scale(p1bullet_original_image, (
    p1bullet_original_image.get_width() // 12, p1bullet_original_image.get_height() // 12))

# Robinho
p2original_image = pygame.image.load("robinho.png")
p2image = pygame.transform.scale(p2original_image, (
    p2original_image.get_width() // 4, p2original_image.get_height() // 4))

p2bullet_original_image = pygame.image.load("tiro.png")
p2bullet_image = pygame.transform.rotate(pygame.transform.scale(p2bullet_original_image, (
    p2bullet_original_image.get_width() // 20, p2bullet_original_image.get_height() // 12)), 90)


# coisos
bulletsp1 = []
bulletsp2 = []


def main():
    run = True
    n = Network()
    startPos = read_pos(n.getPos())
    p = Player(startPos[0], startPos[1], 100, 100, p1image)
    p2 = Player(0, 0, 100, 100, p2image)

    cutscene()

    clock = pygame.time.Clock()

    enemies = []
    for i in range(10):
        e = Enemy()
        enemies.append(e)

    while run:
        clock.tick(60)

        p2Pos = read_pos(n.send(make_pos((p.x, p.y, p.shotCount))))
        p2.x = p2Pos[0]
        p2.y = p2Pos[1]
        if p2.shotCount < p2Pos[2]:
            p2.shotCount = p2Pos[2]
            p2.shot()
        p2.update()

        p.move()
        redrawWindow(win, p, p2, enemies)
        check_collisions(enemies, [p])
        check_collisions(enemies, [p2])
        check_collisions(enemies, bulletsp1)
        check_collisions(enemies, bulletsp2)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                pygame.quit()


main()
