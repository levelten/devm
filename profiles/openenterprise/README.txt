To generate with Drush make, create a stub.make file and enter:

core = "7.x"
api = 2

projects[drupal][type] = core
projects[drupal][version] = "7.10"

projects[openenterprise][type] = profile
projects[openenterprise][download][type] = git
projects[openenterprise][download][url] = http://git.drupal.org/project/openenterprise.git
projects[openenterprise][download][revision] = 7.x-1.0-beta4

;;; Add in some apps (optional). These can be added later from the Apps page as well.
;projects[enterprise_blog][location] = http://apps.leveltendesign.com/fserver
;projects[enterprise_rotator][location] = http://apps.leveltendesign.com/fserver
;projects[enterprise_careers][location] = http://apps.leveltendesign.com/fserver
