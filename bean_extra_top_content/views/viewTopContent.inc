<?php
$view = new view();
$view->name = 'popular_content_oglivyone';
$view->description = 'Shows the most-viewed nodes on the site. This requires the statistics to be enabled at administer >> reports >> access log settings.';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Popular content OglivyONE';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Popular content';
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'type' => 'type',
  'title' => 'title',
  'name' => 'name',
  'timestamp' => 'title',
  'totalcount' => 'totalcount',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'type' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'title' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'timestamp' => array(
    'separator' => '',
  ),
  'totalcount' => array(
    'sortable' => 0,
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = FALSE;
$handler->display->display_options['style_options']['order'] = 'desc';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Author';
/* Field: Content: Has new content */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
/* Sort criterion: Content statistics: Total views */
$handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
$handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
$handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
$handler->display->display_options['sorts']['totalcount']['order'] = 'DESC';
$handler->display->display_options['filter_groups']['operator'] = 'OR';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'AND',
  3 => 'AND',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content statistics: Views today */
$handler->display->display_options['filters']['daycount']['id'] = 'daycount';
$handler->display->display_options['filters']['daycount']['table'] = 'node_counter';
$handler->display->display_options['filters']['daycount']['field'] = 'daycount';
$handler->display->display_options['filters']['daycount']['operator'] = 'not empty';
$handler->display->display_options['filters']['daycount']['group'] = 1;
/* Filter criterion: Access log: Timestamp */
$handler->display->display_options['filters']['timestamp_1']['id'] = 'timestamp_1';
$handler->display->display_options['filters']['timestamp_1']['table'] = 'accesslog';
$handler->display->display_options['filters']['timestamp_1']['field'] = 'timestamp';
$handler->display->display_options['filters']['timestamp_1']['relationship'] = 'uid';
$handler->display->display_options['filters']['timestamp_1']['operator'] = '>';
$handler->display->display_options['filters']['timestamp_1']['value']['value'] = '22:00:00';
$handler->display->display_options['filters']['timestamp_1']['group'] = 2;
/* Filter criterion: Access log: Timestamp */
$handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['filters']['timestamp']['table'] = 'accesslog';
$handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['filters']['timestamp']['relationship'] = 'uid';
$handler->display->display_options['filters']['timestamp']['operator'] = '<';
$handler->display->display_options['filters']['timestamp']['value']['min'] = '22:00:00';
$handler->display->display_options['filters']['timestamp']['value']['value'] = '08:00:00';
$handler->display->display_options['filters']['timestamp']['group'] = 3;

/* Display: Todays Night */
$handler = $view->new_display('block', 'Todays Night', 'todaysnight');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Today\'s night popular content';
$handler->display->display_options['display_description'] = 'Today\'s night popular content';
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
);
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content statistics: Views today */
$handler->display->display_options['sorts']['daycount']['id'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['table'] = 'node_counter';
$handler->display->display_options['sorts']['daycount']['field'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['order'] = 'DESC';
$handler->display->display_options['block_description'] = 'todaysnight';

/* Display: Todays Day */
$handler = $view->new_display('block', 'Todays Day', 'todaysday');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Today\'s day popular content';
$handler->display->display_options['display_description'] = 'Today\'s day popular content';
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
);
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content statistics: Views today */
$handler->display->display_options['sorts']['daycount']['id'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['table'] = 'node_counter';
$handler->display->display_options['sorts']['daycount']['field'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['operator'] = 'OR';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'AND',
  3 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content statistics: Views today */
$handler->display->display_options['filters']['daycount']['id'] = 'daycount';
$handler->display->display_options['filters']['daycount']['table'] = 'node_counter';
$handler->display->display_options['filters']['daycount']['field'] = 'daycount';
$handler->display->display_options['filters']['daycount']['operator'] = 'not empty';
$handler->display->display_options['filters']['daycount']['group'] = 1;
/* Filter criterion: Access log: Timestamp */
$handler->display->display_options['filters']['timestamp_1']['id'] = 'timestamp_1';
$handler->display->display_options['filters']['timestamp_1']['table'] = 'accesslog';
$handler->display->display_options['filters']['timestamp_1']['field'] = 'timestamp';
$handler->display->display_options['filters']['timestamp_1']['relationship'] = 'uid';
$handler->display->display_options['filters']['timestamp_1']['operator'] = '<=';
$handler->display->display_options['filters']['timestamp_1']['value']['value'] = '22:00:00';
$handler->display->display_options['filters']['timestamp_1']['group'] = 2;
/* Filter criterion: Access log: Timestamp */
$handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['filters']['timestamp']['table'] = 'accesslog';
$handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['filters']['timestamp']['relationship'] = 'uid';
$handler->display->display_options['filters']['timestamp']['operator'] = '>=';
$handler->display->display_options['filters']['timestamp']['value']['min'] = '22:00:00';
$handler->display->display_options['filters']['timestamp']['value']['value'] = '08:00:00';
$handler->display->display_options['filters']['timestamp']['group'] = 3;
$handler->display->display_options['block_description'] = 'todaysday';
