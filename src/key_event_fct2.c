#include "../include/fdf.h"
#include "../include/mlx.h"

void	zoom_in(t_struct *s)
{
	if (s->pj.max_heigth < 500 && s->pj.tile_len < 2000 && s->pj.tile_wid < 4000)
	{
		s->pj.max_heigth *= 2;
		s->pj.tile_len *= 2;
		s->pj.tile_wid *= 2;
		s->pj.half_tw = s->pj.tile_wid / 2;
		s->pj.half_tl = s->pj.tile_len / 2;
	}
	project_map(s);
	center_map(s);
	reset_img(s);
	draw_map(s);
}

void	zoom_out(t_struct *s)
{
	if (s->pj.max_heigth > 1 && s->pj.tile_len > 4 && s->pj.tile_wid > 8)
	{
		s->pj.max_heigth /= 2;
		s->pj.tile_len /= 2;
		s->pj.tile_wid /= 2;
		s->pj.half_tw = s->pj.tile_wid / 2;
		s->pj.half_tl = s->pj.tile_len / 2;
	}
//	ft_printf("max_heigth : %d tile_len : %d tile_wid : %d", s->pj.max_heigth, s->pj.tile_len, s->pj.tile_wid);
	project_map(s);
	center_map(s);
	reset_img(s);
	draw_map(s);
}
