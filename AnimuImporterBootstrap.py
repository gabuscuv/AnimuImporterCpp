import unreal;
import argparse;

parser = argparse.ArgumentParser(prog='Animu Importer Bootstrap')

parser.add_argument('-i', '--importFile')      # option that takes a value
parser.add_argument('-d', '--debug',
                    action='store_true')  # on/off flag

animuImporter = unreal.get_editor_subsystem(unreal.AnimuImporterMainSubsystem);

args = parser.parse_args()

unreal.log_warning("AnimuImporterBootstrap"+"\n--------------------\n");
unreal.log_warning("File:" + str(args.importFile));
unreal.log_warning("Debug Mode:" + str(args.debug));