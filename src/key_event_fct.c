#include "../include/fdf.h"
#include "../include/mlx.h"

void	reset_img(t_struct *s)
{
	mlx_destroy_image(s->mlx, s->img.ptr);
	s->img.data = 0;
}
void	move_left(t_struct *s)
{
	if (s->map.mv_x > -1 * s->w_maxx)
		s->map.mv_x -= 10;
	reset_img(s);
	draw_map(s);
}

void	move_right(t_struct *s)
{
	if (s->map.mv_x < s->w_maxx)
		s->map.mv_x += 10;
	reset_img(s);
	draw_map(s);
}

void	move_down(t_struct *s)
{
	if (s->map.mv_x < s->w_maxy)
		s->map.mv_y += 10;
	reset_img(s);
	draw_map(s);
}

void	move_up(t_struct *s)
{
	if (s->map.mv_x > -1 * s->w_maxy)
		s->map.mv_y -= 10;
	reset_img(s);
	draw_map(s);
}
