class Editor
{
	private:
		Toolbar *toolbar;
		MapView *mapView;
		ObjectList *objectList;
		TileList *tileList;
		
	public:
		Editor()
		{
			toolbar=new Toolbar();
			toolbar.render();
			
			
		}	
};